import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.OptionalDouble;
import java.util.function.UnaryOperator;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class StreamTeste5GerandoStream {
    public static void main(String[] args) {
        IntStream.rangeClosed(1, 100).filter(n -> n%2==0).forEach(a -> System.out.println(a+" "));
        IntStream.range(1, 100).filter(n -> n%2==0).forEach(a -> System.out.println(a+" "));

        Stream<String> stream = Stream.of("William", " Text of Stream", "Stream mapper");
        stream.map(String::toUpperCase).forEach(a -> System.out.print(a+" "));
        int nums[] = {1,2,3,4,5};
        OptionalDouble average = Arrays.stream(nums).average();
        System.out.println(average.getAsDouble());

        try(Stream<String> lines = Files.lines(Paths.get("Teste.txt"), Charset.defaultCharset())) {
            lines
                    .flatMap(line -> Arrays.stream(line.split("\n")))
                    .filter(p -> p.contains("File"))
                    .forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();

        }
        Stream.iterate(1, n -> n+2).limit(10).forEach(System.out::println);

        Stream.iterate(new int[]{0,1}, a ->  new int[]{a[1], a[0]+a[1]}).limit(50);
    }
