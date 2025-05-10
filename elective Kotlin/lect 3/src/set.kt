import kotlin.random.Random


fun main(){
    val list=List(100){ Random.nextInt(-10,10) }
    for (el in list){
        println("$el")
    }
    val result= mutableListOf<Int>()
    for (el in list){
        var flag=true
        for (re in result){
            if (re==el)flag=false
            break
        }
        if (flag)result.add(el)
    }
    for (el in result){
        print("$el")
    }
    println()
    println(list.distinct().joinToString(" "))
}