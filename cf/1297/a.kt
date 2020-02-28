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
    var n = readInt()
    if (n <= 999)
        println(n)
    else if (n < 999500)
        println("${(n + 500) / 1000}K")
    else
        println("${(n + 1000000/2) / 1000000}M")
}

fun main() {
    val T = readInt()
    for (_t in 1..T) solve()
}
