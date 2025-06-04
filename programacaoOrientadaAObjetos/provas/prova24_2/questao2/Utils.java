import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Utils {
    public static boolean existe(ArrayList lista, Planta planta) {
        return lista.contains(planta);
    }

    public static Planta[] ordena(List lista) {
        Planta[] listaOrdenada = Arrays.sort(lista);
        return listaOrdenada;
    }
}