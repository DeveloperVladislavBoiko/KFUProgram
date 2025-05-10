import kotlin.math.max

fun main(){
    val a=Array(10){0}
    for (i in 0..<10){
        a[i]= readln().toInt()
    }
    var maxH=Int.MIN_VALUE
    var maxHLocale=0
    for (i in a){
        maxHLocale=max(i+maxHLocale,i)
        if (maxH<maxHLocale){
            maxH=maxHLocale
        }
    }
    if (maxH<maxHLocale){
        maxH=maxHLocale
    }
    println(maxH)
}
//алгоритм кадана прочитать