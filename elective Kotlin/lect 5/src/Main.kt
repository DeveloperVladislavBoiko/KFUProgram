enum class CharType {LETTER, DIGIT,OTHER,SPACE}

fun String.splitMath():List<String>{
    val result= mutableListOf<String>()
    val prevCharType:CharType?=null
    fold(""){acc, it ->
        val charType=when{
            ch.isLetter()->CharType.LETTER
            ch.isDigit()->CharType.DIGIT
            ch.isWhitspace()->CharType.SPACE
            else ->CharType.OTHER
        }
        if (){
            acc+ch
        }
        else {
            result.add(acc)
            acc=""+ch
        }
    }
}

fun main() {
    println("2x^2+sin(x)*x2".splitMath())
    //["2","x","^","2","+","sin","(","x",")","*","x2"]
    //replase sin на
}