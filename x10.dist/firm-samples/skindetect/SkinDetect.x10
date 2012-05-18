import x10.util.IndexedMemoryChunk;

struct Pixel(r: UByte, g: UByte, b: UByte) {
	public def this(r: UByte, g: UByte, b: UByte) {
		property(r, g, b);
	}

	public def isSkinColor(): Boolean {
		val tmpG = g + 15UY;
		val tmpB = b + 15UY;

		return (r > 95UY && g > 40UY && b > 20UY)
		       && ((r > tmpG && r > tmpB && g > b)
		           || (r > tmpG && r > b && b > g));
	}
}

public class SkinDetect {
	public static def printAsPBM(result: Array[Boolean](1),
	                             width: Int, height: Int) {
		val size = width * height;

		Console.OUT.println("P1");
		Console.OUT.println(width + " " + height);
		for (i in 0..(size-1)) {
			Console.OUT.print(result(i) ? "1" : "0");
			val endOfRow = size % width == (width - 1);
			Console.OUT.print(endOfRow ? "\n" : " ");
		}
	}

	public static def main(Array[String]) {
		val width  = ImageData.width;
		val height = ImageData.height;
		val size   = width * height;
		val data   = IndexedMemoryChunk[Pixel](ImageData.getData(), size);
		val pixels = new Array[Pixel](data);

		val result = pixels.map((p: Pixel) => p.isSkinColor());
		printAsPBM(result, width, height);
	}
}
