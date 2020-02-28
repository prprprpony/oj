private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    var x = readIntArray()
    x.sort()
    var ans = IntArray(3)
    for (i in 0..2) {
        ans[i] = x[3] - x[i]
    }
    println(ans.joinToString(" "))
}
