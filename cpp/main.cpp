#include <jni.h>

int main(int argc, char **argv)
{
    JNIEnv *env;
    JavaVM *jvm;

    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_1_8;

    JavaVMOption options[argc];
    for (int i = 0; i < argc; i++)
    {
        options[i].optionString = argv[i + 1];
    }
    vm_args.options = options;
    vm_args.nOptions = argc - 1;
    vm_args.ignoreUnrecognized = false;

    JNI_GetDefaultJavaVMInitArgs(&vm_args);

    auto create_jvm_res = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);

    if (create_jvm_res != JNI_OK)
    {
        printf("Failed to create JVM\n");
        return 1;
    }

    auto cls = env->FindClass("example/Hello");
    if (cls == NULL)
    {
        if (env->ExceptionOccurred())
        {
            env->ExceptionDescribe();
        }
        else
        {
            printf("clsMain is null but no exception was thrown.\n");
        }

        jvm->DestroyJavaVM();
        return 1;
    }

    auto mid = env->GetStaticMethodID(cls, "add", "(II)I");
    if (mid == NULL)
    {
        if (env->ExceptionOccurred())
        {
            env->ExceptionDescribe();
        }
        else
        {
            printf("mid is null but no exception was thrown.\n");
        }

        jvm->DestroyJavaVM();
        return 1;
    }
    auto result = env->CallStaticIntMethod(cls, mid, 1, 2);

    printf("Result: %d\n", result);

    jvm->DestroyJavaVM();

    return 0;
}