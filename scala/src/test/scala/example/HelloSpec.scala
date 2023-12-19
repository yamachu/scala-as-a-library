package example

class HelloSpec extends munit.FunSuite {
  test("1 + 2 = 3") {
    assertEquals(Hello.add(1, 2), 3)
  }
}
