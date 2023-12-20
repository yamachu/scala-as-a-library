# Scala as a library

C言語からScalaで作成したライブラリを呼び出すサンプル

## Notes

[SBT Native Packager](https://github.com/sbt/sbt-native-packager) の JlinkPlugin を使用し、Custom JRE を作成しています。
C言語などの呼び出し側のプログラムは、Custom JRE に含まれるライブラリを使用することで、動作環境の Java 非依存で実行出来ます。

### Notice

cpp プロジェクトの Makefile に記述してあるように、Java VM に対してオプションを渡す必要があります。
`-Djava.class.path` で Scala runtime の jar や、実際の Scala ライブラリの jar を指定します。
separator は macOS や Linux は `:` で、Windows は `;` を使用します。
