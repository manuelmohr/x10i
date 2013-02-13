import x10.array.Array;
import x10.lang.Math;

public class NQueens {
    static class Board(n: Int) {
        val row = new Array[Int](0..(n-1));

        private def can_place(column: Int) {
            for (i in 0..(column-1)) {
                if (row(i) == row(column) || Math.abs(row(column)-row(i)) == (column-i))
                    return false;
            }
            return true;
        }

        public def solve() {
            var n_solutions: Int = 0;
            var column     : Int = 0;
            row(0) = -1;
            while (column >= 0) {
                row(column)++;
                /* search for a row to place the queen */
                while (row(column) < n && !can_place(column)) {
                    row(column)++;
                }
                /* successfully placed a queen? */
                if (row(column) < n) {
                    if (column == n-1) {
                        /* found a complete solution */
                        n_solutions++;
                    } else {
                        /* advance to next column */
                        column++;
                        row(column)=-1;
                    }
                } else {
                    /* dead end, backtrack */
                    column--;
                }
            }
            return n_solutions;
        }
    }

    public static def main(args:Array[String](1))  {
        val max = 8;
        for (n in 1..max) {
            val board  = new Board(n);
            val result = board.solve();
            Console.OUT.println("NQueens(" + n + ") = " + result);
        }
    }
}
