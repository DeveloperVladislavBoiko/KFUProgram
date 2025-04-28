import java.util.Collections.min

fun clearStr(str:String):String{
        var str1=str
        str1=str.replace(Regex("[:]+"), ":")
        str1=str1.replace(Regex("[ ]+"), " ")
        str1=str1.replace(": ",":")
        str1=str.replace(" :",":")
    return str1
    ///////////////иногда непраильно чистит
}


fun main(){
    println("введите время вылетов в формате h1:minuts1 h2:minuts2  ... ")
    val str=clearStr(readln())
    val departures= (str.split(":", " ")).map{ it.toInt()}
    val departuresHINMinuts=((departures.filterIndexed { index, _ -> index % 2 == 0 }).map{it*60})
    val departuresMinuts=departures.filterIndexed { index, _ -> index % 2 == 1 }
    val depart=departuresMinuts.zip(departuresHINMinuts){h1, h2 -> h1+h2}// склеиваем список минут и список часов переведенных в минуты поэлементно
    println("введите время вашего вылета в формате h1:minuts1 h2:minuts2  ... ")
    val myDepartList=(readln().split(":").map { it.toInt()  })
    val myDepart=myDepartList[0]*60+myDepartList[1]
    if ((depart.filter{it>myDepart}).size!=0) {
        println("ближайший вылет к вашему это"+
            departures[2 * depart.indexOf(min(depart.filter { it > myDepart }))].toString()
                + ":" + departures[1 + 2 * depart.indexOf(
                min(depart.filter { it > myDepart })
            )].toString()
        )
    }
    else {
        println("не найден подходящий рейс")
    }
}


