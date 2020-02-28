import kotlin.math.*
import java.util.PriorityQueue
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
val a = mutableListOf< Pair<Int,Pair<Int, Int>> >()

fun ok(n : Int, m : Int, t : IntArray): Int {
    var d = 0
    var cur = 0
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy{it.first})
    var i = 0
    while (pq.size > 0 || i < n) {
        cur++
        if (pq.size == 0)
            cur = a[i].second.first
        while (i < n && a[i].second.first == cur) {
            pq.add(Pair(a[i].second.second, a[i].first))
            i++
        }
        var tot = m
        while (pq.size > 0 && tot > 0) {
            val (r, j) = pq.peek()
            pq.remove()
            if (r < cur) {
                d = max(d, cur - r)
            }
            t[j] = cur
            tot--
        }
    }
    return d
}

fun solve() {
    val (n, m) = readInts()
    a.clear()
    for (i in 0..n-1) {
        var (x, y) = readInts()
        a.add(Pair(i, Pair(x, y)))
    }
    a.sortWith(compareBy({it.second.first})) // sort pair
    val t = IntArray(n)
    var l = ok(n, m, t)
    println(l)
    println(t.joinToString(" "))
}

fun main() {
    val T = readInt()
    for (_t in 1..T) solve()
}
