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
val N = 312345
val g = Array(N, { mutableSetOf<Int>() } )

fun solve() {
    val (n, k) = readInts()
    for (i in 1..n) g[i].clear()
    for (i in 1..n-1) {
        val (x, y) = readInts()
        g[x].add(y)
        g[y].add(x)
    }
    if (k == 1) {
        println("Yes")
        println(1)
        println(1)
        return
    }
    val a = mutableListOf<Int>()
    for (i in 1..n) {
        if (g[i].size == 1)
            a.add(i)
    }
    if (a.size < k) {
        println("No")
        return
    }
    val b = IntArray(n + 1)
    while (a.size > k) {
        val u = a[a.size - 1]
        a.removeAt(a.size - 1)
        b[u] = 1
        val v = g[u].elementAt(0)
        g[u].remove(v)
        g[v].remove(u)
        if (g[v].size == 1)
            a.add(v)
    }
    val ans = mutableListOf<Int>()
    for (i in 1..n)
        if (b[i] == 0)
            ans.add(i)
    println("Yes")
    println(ans.size)
    println(ans.joinToString(" "))
}

fun main() {
    val T = readInt()
    for (_t in 1..T) solve()
}
