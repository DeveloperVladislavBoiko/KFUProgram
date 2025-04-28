fun main(){
    val str = (readln().filter { it.isLetter() or it.isDigit() }).lowercase()
    /*
    filter метод оставляющий только те элементы которые в лямбда выражении дают true
    isLetter() метод проверяющий является ли символ буквой
    isDigit() метод проверяющий является ли символ числом
    lowercase() // делаем все символы строчными, изменение регистра
     */
    val strReversed=str.reversed()
    println("эта строка ${if (str==strReversed) "" else "не"} паллидром")
}