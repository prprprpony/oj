private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main() {
    val n = readInt()
    val a = readIntArray()
    val st = mutableSetOf<Int>()
    val li = mutableListOf<Int>()
    a.reverse()
    for (x in a) {
        if (x !in st) {
            st.add(x)
            li.add(x)
        }
    }
    li.reverse()
    println(li.size)
    println(li.joinToString(" "))
}
