import SimpleLib;

public class TestObject {
  var field : int;

  public static def main(Array[String]) {
    val to = new TestObject();
    to.field = 42;
    SimpleLib.print(to.field);
  }
}
