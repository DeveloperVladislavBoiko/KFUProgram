//enum class CharType {LETTER, DIGIT,OTHER,SPACE}
//
//fun String.splitMath():List<String>{
//    val result= mutableListOf<String>()
//    val prevCharType:CharType?=null
//    fold(""){acc, it ->
//        val charType=when{
//            ch.isLetter()->CharType.LETTER
//            ch.isDigit()->CharType.DIGIT
//            ch.isWhitspace()->CharType.SPACE
//            else ->CharType.OTHER
//        }
//        if (ch.){
//            acc+ch
//        }
//        else {
//            result.add(acc)
//            acc=""+ch
//        }
//    }
//}


enum class CharType {LETTER, DIGIT,OTHER,SPACE}

fun examinationPush(prev:Char?, ch:Char):Boolean{
    //if (ch==' ') return false
    if (prev==null){
        return true
    }
    if (prev.isLetter() && ch.isDigit ()){
        return true
    }
    if (prev.isLetter() && ch.isLetter() ){
        return true
    }
    if (prev.isDigit() && ch.isDigit() ){
        return true
    }

    if (prev.isDigit() && ch.isLetter() ){
        return true
    }
    if (prev==null){
        return true
    }
    return false
}

fun String.splitMath():List<String>{
    val result= mutableListOf<String>()
    val prevCharType:CharType?=null
    var acc=""
    var prev:Char?=null
    for (ch in this){
        if (examinationPush(prev,ch)){
            acc+=ch
            prev=ch
        }
        else {
            result.add(acc)
            acc = ""
            prev = null
        }
    }
    return result
}


fun main() {
    println("2x^2+sin ( x ) *   x2".splitMath())
    //["2","x","^","2","+","sin","(","x",")","*","x2"]
    //replase sin на
}

