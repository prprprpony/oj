import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    val (n, w) = readInts()
    val a = readIntArray()
    var s : Int = 0
    var mx = 0
    var mn = 0
    for (x in a) {
        s += x
        mx = max(mx, s)
        mn = min(mn, s)
    }
    var vl = 0
    var vr = w
    if (mn < 0) {
        vl = -mn
        mn += vl
        mx += vl
    }
    if (mx > w) {
        vr = vl - 1
    } else {
        vr = w + vl - mx
    }
    vr = min(vr, w)
    println(if (vr < vl) 0 else vr - vl + 1)
}
