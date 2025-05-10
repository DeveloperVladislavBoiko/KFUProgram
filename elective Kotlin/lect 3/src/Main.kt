fun main() {
    val list= listOf(12,24,24,235,1,-1)
    var maxh=list[0]
    for (i in list){
        if(maxh<i) maxh=i
    }
    println(maxh)

    println(list.max())
}