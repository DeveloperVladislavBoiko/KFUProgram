fun toPair(time:String):Pair<Int,Int>{
    time
        .split(delimiters=":",".")
        .map{ it.toInt()}
        .let{it[0] to it[1]}
}

fun Int.toTimeString()="${this/60}:${this%60}"

val Pair<Int,Int>.inMinuts get()=first*60 +second

fun getFlightTime(departures: String,arrived:String ):Int{
    val t1=toPair(departures).inMinuts
    val t2=toPair(arrived).inMinuts
    return (t2-t1+1440)%1440

}

fun getNearearestFliLength(flight1:Pair<String,String>, flight2: Pair<String, String>):Int{
    val t1 =getFlightTime(flight1.first, flight1.second)
    val t2=getFlightTime(flight2.first, flight2.second)
    return ((t1+t2)/2).toTimeString()

}

fun getNearearestFliAfter(departures:List<String>, requestedTime: String )=toPair(requestedTime).run {
        val limit=first*60+second
        departures.map{toPair(it).let{it.first*60 +it.second}
            .apply { filter { it > limit }.minOrNull()?.let {
            } }?:                         //////////////////
}

fun main() {
    val depatrures= listOf("8:31", "12;45","17;30", "22;15")
    val myTime="14;00"
    println(getNearearestFlyAfter(depatrures, requestedTime = myTime))

}