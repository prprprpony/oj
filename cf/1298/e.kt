import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    val (n, k) = readInts()
    val r = readIntArray()
    var ans = IntArray(n)
    for (i in 1..k) {
        var (x, y) = readInts()
        --x
        --y
        if (r[y] < r[x])
            x = y.also{y = x}
        if (r[x] < r[y])
            ans[y]--
    }
    val A = IntArray(n){ i -> i }.sortedWith(compareBy({ r[it] }, { it }))
    var j = 0
    for (i in 0..n-1) {
        while (j < n && r[A[j]] < r[A[i]])
            ++j
        ans[A[i]] += j
    }
    println(ans.joinToString(" "))
}
