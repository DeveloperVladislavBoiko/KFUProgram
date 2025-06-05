import java.util.Stack
import kotlin.Int.Companion.MIN_VALUE
import kotlin.math.max
import kotlin.math.pow

//val String.isBinaryOperator get()=when(this){
//    "^","+","-","*","/","%" -> true
//    else ->false
//}
//
//val String.isUnaryOperator get()=when(this){
//    "~","!" -> true
//    else ->false
//}
//

fun Char.isFloatDigit()=isDigit()||this=='.'

fun examinationPush (prev: Char?, ch:Char) = (prev==null)
        || (prev.isLetter() && ch.isLetter())
        || (prev.isFloatDigit() && ch.isFloatDigit())
        || (prev.isLetter() && ch.isFloatDigit())



fun String.unaryMinus(): String {
    if (this.isEmpty()) return this

    val firstChar = if (this[0] == '-') '~' else this[0]
    var result = firstChar + this.substring(1)

    return result.replace("(-", "(~")
        .replace("[-", "[~")
        .replace("<-", "<~")
        .replace("{-", "{~")
}

fun String.splitMath(): List<String>{
    //this=unaryMinus(this)
    val result = mutableListOf<String>()
    var prev:Char?=null
    return result.run{
        add(this@splitMath.unaryMinus().fold(""){ acc, ch ->
            if (prev == null || !examinationPush(prev,ch)){
                prev=ch
                result.add(acc)
                "" + ch
            }else{
                acc + ch
            }
        })
        filter{it.isNotBlank()}
    }
}
//
//val String.priority get()=when(this){
//    ")","]","}",">" -> -1
//    "~","!"->0
//    "+","-" -> 1
//    "*","/","%" -> 2
//    //"~" -> 3
//    "sin","cos","tg","ctg","ln","lg"->4
//    "^"->5
//    //"!"->6
//    "(","[","{","<" -> 7
//    else ->Int.MIN_VALUE
//}
//
//val String.stackNotBraket get()=when(this){
//    "("->false
//    "["->false
//    "{"->false
//    "<"->false
//    else ->true
//}
//
//val String.stackNotBraketEnd get()=when(this){
//    ")"->false
//    "]"->false
//    "}"->false
//    ">"->false
//    else ->true
//}

val String.isBinaryOperator get()=when(this){
    "^","+","-","*","/","%" -> true
    else ->false
}

val String.isUnaryOperator get()=when(this){
    "~","!" -> true
    else ->false
}



//fun clearStack(stackOperators:Stack<String>,result: MutableList<String>){
//    while (!stackOperators.empty()){
//        result.add(stackOperators.pop())
//    }
//}
//
//
//fun clearStackBraker(stackOperators:Stack<String>,result: MutableList<String>){
//    if (stackOperators.empty()) return
//    var h=stackOperators.pop()
//    while (h.stackNotBraket && (!stackOperators.empty())){
//        if (h.stackNotBraketEnd)result.add(h)
//        h=stackOperators.pop()
//    }
//    if (stackOperators.empty() &&  h.stackNotBraket)result.add(h)
//}
//
//
//fun OPN(lst:List<String>): MutableList<String>{
//    val result:MutableList<String> = mutableListOf()
//    val stackOperators=Stack<String>()
//    var maxPriority=-1
//    for (i in lst) {
//        if (i.priority == Int.MIN_VALUE) {
//            result.add(i)
//        }
//        else {
//            if(maxPriority>i.priority){/////////>=
//                clearStackBraker(stackOperators, result)
//                maxPriority = Int.MIN_VALUE
//                if (i.stackNotBraketEnd) stackOperators.push(i)
//            }
//            else {
//                maxPriority = max(maxPriority, i.priority)
//                if (i.stackNotBraketEnd) stackOperators.push(i)//////////////////
//            }
//        }
//    }
//    clearStack(stackOperators,result)
//    return result
//}


val String.priority get()=when(this){
    ")","]","}",">" -> -1
    "(","[","{","<" -> 0
    "+","-" -> 1
    "*","/","%" -> 2
    "~" -> 3
    "sin","cos","tg","ctg","ln","lg"->4
    "^"->5
    "!"->6
    else -> Int.MIN_VALUE
}

fun toRpn(expr: List<String>): List<String>{
    val result = mutableListOf<String>()
    val opsOperators = Stack<String>()
    expr.forEach {
        if(it.priority == Int.MIN_VALUE) result.add(it)
        else {
            val el = if(it == "-"
                && (opsOperators.isEmpty()
                        && result.isEmpty()
                        || opsOperators.peek().priority == 0)
            ) "~"
            else it
            if(el.priority == 0 || opsOperators.isEmpty() || el.priority >= opsOperators.peek().priority){
                opsOperators.push(el)
            }
            else{
                while (opsOperators.isNotEmpty() && opsOperators.peek().priority > el.priority){
                    opsOperators.pop().also { op ->
                        if(op.priority > 0) result.add(op)
                    }
                }
                if(el.priority > 0){
                    opsOperators.push(el)
                }
            }
        }
    }
    while(opsOperators.size > 0){
        result.add(opsOperators.pop())
    }
    return result
}


fun newElem(h1:String,h2:String,operator:String,):Double?{
    return when (operator){
        "+"->  h2.toDouble()+h1.toDouble()
        "^"->  h2.toDouble().pow(h1.toDouble())
        "-"->  h2.toDouble()-h1.toDouble()
        "*"->  h2.toDouble()*h1.toDouble()
        "/"->  h2.toDouble()/h1.toDouble()
        "%"->  h2.toDouble()%h1.toDouble()
        else -> null
    }
}

fun fact(h:Int):Double{
    var s=1.0
    for (i in (2.. h)) {
        s*= i
    }
    return s
}

fun newElem(h1:String,operator:String,):Double?{
    return when (operator){
        "~"->  -h1.toDouble()
        "!"->  fact(h1.toInt())
        else -> null
    }
}

fun countMath(lstMathOPN: List<String>): Double   {
    val stack = Stack<String>()
    for (i in lstMathOPN) {
        if (i.isBinaryOperator ||  i.isUnaryOperator) {
            if (i.isBinaryOperator) {
                stack.add(newElem(stack.pop(), stack.pop(), i).toString())
            }
            else {
                stack.add(newElem(stack.pop(), i).toString())
            }
        }
        else {
            stack.add(i)
        }
    }
    return stack.pop().toDouble()
}

//fun unaryMinus(str:String):String{
//    if (str[0]=='-') str[0]='~'
//    return str.replace("(-","(~").replace("[-","[~").replace("<-","<~").replace("{-","{~")
//}



////// не рабочий тест (-3+2!)/((-2)^6-1)






fun main(){
    val str=readln()
    println(toRpn(str.splitMath()))
    println(countMath(toRpn(str.splitMath())))
}