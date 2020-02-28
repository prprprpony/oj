import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    val n = readInt()
    val s = readLn()
    var cur = 0
    var ans = 0
    for (i in 0..n-1) {
        if (s[i] == 'x') {
            cur++
        } else {
            ans += max(0, cur - 2)
            cur = 0
        }
    }
    ans += max(0, cur - 2)
    println(ans)
}
