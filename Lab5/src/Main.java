public class Main {

    public static void main(String[] args) {
        Numbers myNumbers = new Numbers();

        // Добавим в множество несколько чисел
        myNumbers.addNumber(6);
        myNumbers.addNumber(5);
        myNumbers.addNumber(9);
        myNumbers.addNumber(-1);
        myNumbers.addNumber(-8);
        myNumbers.addNumber(0);

        // Выведем произведения по группам
        System.out.println("Отрицательные произведения: " + myNumbers.getProds()
                .filter(x -> x < 0)
                .toList());
        System.out.println("Нулевые произведения: " + myNumbers.getProds()
                .filter(x -> x == 0)
                .toList());
        System.out.println("Положительные произведения: " + myNumbers.getProds()
                .filter(x -> x > 0)
                .toList());

        // Получим число "X"
        if (myNumbers.getX().isPresent()) {
            System.out.println("Число \"X\": " + myNumbers.getX().get());
        } else {
            System.out.println("Число \"X\" не найдено!");
        }

    }
}
