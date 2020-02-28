import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun DC(a: IntArray, l: Int, r: Int): Long {
    if (r - l == 1) {
        return 0
    }
    val m = (l + r) / 2
    //println("l=${l}, m = ${m}, r = ${r}")
    var ret = DC(a, l, m) + DC(a, m, r)
    val al = mutableListOf<Int>()
    val ar = mutableListOf<Int>()
    for (i in l..m-1)
        al.add(a[i])
    al.add(1000000)
    for (i in m..r-1)
        ar.add(a[i])
    ar.add(1000000)
    var k = l
    var i = 0
    var j = 0
    while (!(al[i] == 1000000 && ar[j] == 1000000)) {
    //    println("k=${k},i=${i},j=${j},al[i]=${al[i]},ar[j]=${ar[j]}")
        if (ar[j] <= al[i]) {
            ret += al.size - 1 - i
            a[k++] = ar[j++]
        } else {
            a[k++] = al[i++]
        }
    }
    return ret
}

fun sol(p: IntArray, m : Int): Long {
    val n = p.size
    var a = mutableListOf<Int>(0)
    var s = 0
    for (i in 0..n-1) {
        s += if (p[i] <= m) -1 else 1
        a.add(s)
    }
    //println(a.joinToString(" "))
    return DC(a.toIntArray(), 0, n + 1)
}

fun main() {
    val (n, m) = readInts()
    val p = readIntArray()
    println(sol(p, m) - sol(p, m - 1))
}
