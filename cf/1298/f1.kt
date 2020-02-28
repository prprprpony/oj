import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    val (n, m) = readInts()
    val p = readIntArray()
    var j = 0
    var ans : Long = 0
    while (p[j] != m)
        ++j
    var s = 0
    val mp = mutableMapOf<Int,Int>()
    for (i in j downTo 0) {
        s += if (p[i] <= m) -1 else 1
        if (s == 0 || s == -1)
            ++ans
        var t = if (mp.get(s) == null) 1 else mp[s]!! + 1
        mp[s] = t
    }
    s = 0
    for (i in j + 1 .. n - 1) {
        s += if (p[i] <= m) -1 else 1
        var t = mp.get(-s)
        if (t != null)
            ans += t
        t = mp.get(-1 - s)
        if (t != null)
            ans += t
    }
    println(ans)
}
