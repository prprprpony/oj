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

val inf = 1000000000

fun solve() {
    val n = readInt()
    val a = readIntArray()
    var mx = -inf
    var mxi = -1
    var mn = inf
    var mni = -1
    var s = 0
    val b = IntArray(n)
    for (i in 0..n-1) {
        var x = a[i]
        if (x > 0) {
            b[i] = 1
            s += x
            if (x < mn) {
                mn = min(mn, x)
                mni = i
            }
        } else if (x < 0) {
            if (x > mx) {
                mx = max(mx, x)
                mxi = i
            }
        }
    }
    var ans = max(s - mn, s + mx)
    if (ans == s-mn)
        b[mni] = 0
    else
        b[mxi] = 1
    println(ans)
    println(b.joinToString(""))
}

fun main() {
    val T = readInt()
    for (_t in 1..T) solve()
}
