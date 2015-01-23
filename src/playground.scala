object playground {

	def add(res: Double, x: Double) = {
		res + x
	}

	def main(args: Array[String]) = {
	
	  val f = List(0.5, 0.4, 0.1, 0.0)
	  val g = List(0.0, 0.2, 0.5, 0.3)
	  
	  val elementCount = f.length - 1
	  val indices = List.range(0, elementCount)

	  val leftList = for (i <- indices) yield (0 to i toList).zip(elementCount - i to elementCount toList)
	  val middleList = List((0 to elementCount toList).zip(0 to elementCount toList))
	  val rightList = for (element <- leftList.reverse) yield for(pair <- element) yield pair.swap

	  val total = leftList ::: middleList ::: rightList

	  for (operation <- total) println((for (n <- operation) yield f(n._1) * g(n._2)).reduceLeft(add))

	}
	
}