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

val dp = Array(50000, {mutableMapOf<Int, Long>()})

fun cal(len : Int, x: Int): Long {
    if (len == 1) {
        if (x > 9 || x < 1)
            return 0
        return 1
    }
    var w = dp[len].getOrElse(x){-1}
    if (w.compareTo(-1) == 0) {
        w = 0
        for (i in 1..9) {
            if (x % i == 0) {
                w += cal(len - 1, x / i)
            }
        }
        dp[len].put(x, w)
    }
    return w
}

fun solve() {
    val (m, k) =  readInts()
    val pr = arrayOf(2, 3, 5, 7)
    val cnt = IntArray(4)
    var tmp = m
    for (i in 0..3) {
        while (tmp % pr[i] == 0) {
            tmp /= pr[i]
            cnt[i]++
        }
    }
    if (tmp > 1) {
        println(-1)
        return
    }
    for (i in 1..9) {
        dp[1].put(i, 1)
    }
    var len = 1
    var tot : Long = 0
    while (tot < k) {
        val w = cal(len, m)
        if (tot + w < k) {
            tot += w
            len++
        } else {
            break
        }
    }
    var ans = mutableListOf<Int>()
    //println("${len}, ${tot}, ${k}")
    tmp = m
    for (i in len downTo 1) {
        if (i == 1) {
            assert(1 <= tmp && tmp <= 9)
            ans.add(tmp)
            break
        }
        for (j in 1..9) {
            if (tmp % j == 0) {
                val w = cal(i - 1, tmp / j)
                //println("i=${i}, w=${w}, j=${j}, len-1 =${len-1}, tmp/j=${tmp/j}")
                if (tot + w < k) {
                    tot += w
                } else {
                    tmp /= j
                    ans.add(j)
                    break
                }
            }
        }
    }
    //println(ans.joinToString(" "))
    println(ans.joinToString(""))
}

fun main() {
    val T = 1
    for (_t in 1..T) solve()
}
