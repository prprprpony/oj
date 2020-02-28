import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun bins(a : List<Int>, v : Int) : Int {
    var k = 1
    while (k < a.size)
        k += k
    var j = 0
    while (k > 0) {
        var jj = j + k
        if (jj < a.size && a[jj] <= v)
            j = jj
        k = k / 2
    }
    if (a[j] <= v)
        return j
    else
        return -1
}

class FenwickTree(n_ : Int) {
    val n = n_
    val f = LongArray(n + 1)
    fun lowbit(i : Int) = i and -i 
    fun add(x : Int, v : Long) {
        var i = x
        while (i <= n) {
            f[i] += v
            i += lowbit(i)
        }
    }
    fun sum(x : Int) : Long {
        var i = x
        var ret: Long = 0
        while (i > 0) {
            ret += f[i]
            i -= lowbit(i)
        }
        return ret
    }
}

/*
val N = 20005
val d = Array(N, { mutableListOf<Int>() } )

val a = readIntArray()
println(a.joinToString(" "))

a = b.also { b = a } // swap a b
ap.sortWith(compareBy({it.first}, {it.second})) // sort pair
val vx = x.sorted().distinct() // sort and unique
*/

fun solve() {
    var (n, k) = readInts()
    val a = readIntArray()
    if (n == 1) {
        println(k)
        return
    }
    var ap = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})
    ap.sortWith(compareBy({it.first}, {it.second})) // sort pair
    for (i in n-2 downTo 0) {
        var x = ap[i + 1].first - ap[i].first - 1
        x = min(x, k)
        ap[i] = Pair(ap[i].first + x, ap[i].second)
        k -= x
    }
    var q = k / n
    var r = k % n
    val d = IntArray(n)
    for (i in n-1 downTo 0) {
        ap[i] = Pair(ap[i].first + q, ap[i].second)
        if (n - i <= r)
            ap[i] = Pair(ap[i].first + 1, ap[i].second)
        d[ap[i].second] = ap[i].first - a[ap[i].second]
    }
    println(d.joinToString(" "))
}

fun main() {
    val T = readInt()
    for (_t in 1..T) solve()
}
