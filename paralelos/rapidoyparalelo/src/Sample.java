import org.omg.PortableServer.THREAD_POLICY_ID;

import java.util.List;
import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.*;

public class Sample {

    private static int generador(){
        return 2;
    }

    private static int printIt(int i){
        System.out.println("El thread N°" + Thread.currentThread().toString() + String.format(" tiene el numero %d" ,i ));
        return 0;
    }

    public static void main(String[] args){
        List<Integer> numbers= Arrays.asList(1,2,3,4,5,6,7,8,9,10);
        int x;
        ForkJoinPool pool = new ForkJoinPool(10);
        ForkJoinPool pool2 =new ForkJoinPool(5);
        CompletableFuture<Integer> futuro = CompletableFuture.supplyAsync(Sample::generador,pool);

        //Sleep.sleep(1000);
        futuro.thenAcceptAsync(Sample::printIt,pool2);

        System.out.println(Runtime.getRuntime().availableProcessors());
        x = numbers.stream()
                .filter(e -> e%2==0)
                .mapToInt(e -> e*2)
                .sum();
        System.out.println(String.format("Los impares multiplicados por dos tienen suma:%d", x));
        numbers.stream()
                .parallel() //cambia el efecto al usarlo
                .map( Sample::printIt)
                .forEach(e->{}); //Si esta linea no esta no se imprime nada!!->es Lazy
    }

}