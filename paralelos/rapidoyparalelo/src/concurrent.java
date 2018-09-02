import java.util.concurrent.Semaphore;
import java.util.concurrent.*;
import java.io.*;

class CountSem extends Thread {
static volatile int n = 0;
static Semaphore s = new Semaphore(1);

public void run() {
 int temp;
 for (int i = 0; i < 10; i ++) {

    try { s. acquire (); }
    catch (InterruptedException e) { }//java.io.Console.println("no");}
    temp = n;
    n = temp + 1;
    s. release ();
    }

}

public static int main(String[] args ) {
    CountSem contador = new CountSem();
    contador.run();
    return 0;
}

}