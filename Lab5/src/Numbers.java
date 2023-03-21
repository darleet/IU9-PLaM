import java.util.*;
import java.util.stream.Stream;

public class Numbers {
    private final HashSet<Integer> numbers = new HashSet<>();

    public void addNumber(Integer number) {
        this.numbers.add(number);
    }

    public Stream<Integer> getProds() {
        HashSet<Integer> results = new HashSet<>();
        numbers.forEach(x -> numbers.stream()
                .parallel()
                .filter(y -> !Objects.equals(y, x))
                .forEach(y -> results.add(x * y)));
        return results.stream();
    }

    public Optional<Integer> getX() {
        return numbers.stream()
                .filter(x -> numbers.stream().allMatch(y -> Objects.equals(y, x) ||
                        Math.abs(y) < Math.abs(x)))
                .findAny();
    }
}
