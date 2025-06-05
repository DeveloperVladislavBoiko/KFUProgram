import java.util.Stack
import kotlin.Int.Companion.MIN_VALUE
import kotlin.math.max


fun Char.isFloatDigit()=isDigit()||this=='.'

fun examinationPush (prev: Char?, ch:Char) = (prev==null)
        || (prev.isLetter() && ch.isLetter())
        || (prev.isFloatDigit() && ch.isFloatDigit())
        || (prev.isLetter() && ch.isFloatDigit())


fun String.splitMath(): List<String>{
        val result = mutableListOf<String>()
        var prev:Char?=null
        return result.run{
                add(this@splitMath.fold(""){ acc, ch ->
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

val String.priority get()=when(this){
        ")","]","}",">" -> -1
        "+","-" -> 1
        "*","/","%" -> 2
        "~" -> 3
        "sin","cos","tg","ctg","ln","lg"->4
        "^"->5
        "!"->6
        "(","[","{","<" -> 7
        else ->Int.MIN_VALUE
}

//fun clearStack(stackOperators:Stack<String>,result: MutableList<String>){
//        while (!stackOperators.empty()){
//                result.add(stackOperators.pop())
//        }
//}

val String.stackNotBraket get()=when(this){
        "("->false
        "["->false
        "{"->false
        "<"->false
        else ->true
}

val String.stackNotBraketEnd get()=when(this){
        ")"->false
        "]"->false
        "}"->false
        ">"->false
        else ->true
}

fun clearStack(stackOperators:Stack<String>,result: MutableList<String>){
        while (!stackOperators.empty()){
                result.add(stackOperators.pop())
        }
}


fun clearStackBraker(stackOperators:Stack<String>,result: MutableList<String>){
        if (stackOperators.empty()) return
        var h=stackOperators.pop()
        while (h.stackNotBraket && (!stackOperators.empty())){
                if (h.stackNotBraketEnd)result.add(h)
                h=stackOperators.pop()
        }
        if (stackOperators.empty() &&  h.stackNotBraket)result.add(h)
}


fun OPN(lst:List<String>): MutableList<String>{
        val result:MutableList<String> = mutableListOf()
        val stackOperators=Stack<String>()
        var maxPriority=0
        for (i in lst) {
                if (i.priority == Int.MIN_VALUE) {
                        result.add(i)
                }
                else {
                        if(maxPriority>=i.priority){
                                clearStackBraker(stackOperators, result)
                                maxPriority = Int.MIN_VALUE
                                if (i.stackNotBraketEnd) stackOperators.push(i)
                        }
                        else {
                                maxPriority = max(maxPriority, i.priority)
                                if (i.stackNotBraketEnd) stackOperators.push(i)//////////////////
                        }
                }
        }
        clearStack(stackOperators,result)
        return result
}
//"^","+","-","*","/","%"


///                if( i.isUnaryOperator){
//                        stack.add(newElem(stack.pop(),i))
//                }
//val list1 = listOf(1, 2, 3)
//val list2 = listOf(4, 5, 6)
//
//val number = 2
//
//when (number) {
//        in list1 -> println("Число $number в списке list1")
//        in list2 -> println("Число $number в списке list2")
//        else -> println("Число $number ни в одном списке")
//}

fun main(){
        val str=readln()
        println(OPN(str.splitMath()))
        //println(OPN(["2","*","35","+","67","^","5"]))
}