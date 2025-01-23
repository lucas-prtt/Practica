using System;

namespace HelloWorld{

class HelloWorld
{
    static void Main(string[] args){
        //Hola
        /*
        Mundo
        */
        Console.WriteLine("Hello, World!");

        int codigo = 100;
        codigo++;
        codigo+=5;
        float precioPesos = 948.99f;
        double precioDolares = 0.89;
        string palabra = "alfombra";
        Console.WriteLine(codigo + " - " + palabra + ": AR$ " + precioPesos + " (U$D " + precioDolares + ")" );
        
        dynamic din = 2;
        Console.WriteLine(din);
        din = "Chau";
        Console.WriteLine(din);

        var datoInferido = 4;
        Console.WriteLine(datoInferido+33);
        Console.WriteLine($"Un numero es }}{{ {din} y otro es {codigo} o {precioDolares}");
        const string unaConstante = "Constantinopla";
        Console.WriteLine(unaConstante);

        var array = new int[] {1, 2, 3, 5, 6, 2 , 4, 5};
        var otroArray = new int[9];
        otroArray = [1, 1, 1, 1, 1, 1, 1, 1, 1];
        Console.WriteLine(array[5]);
        Console.WriteLine(otroArray);

        var Precios = new Dictionary<string, double>
        {
            {"pepitos", 2000},
            {"oreos", 3000},
            {"pitusas", 1300}
        };
        Console.WriteLine("Pitusas: " + Precios["pitusas"]);

        var unSet = new HashSet<string>{
            "hola" , "Hallo", "Hello"
        };
        Console.WriteLine(unSet);

        for(int i = 0; i<5; i++){
            Console.WriteLine(i);
        };
        foreach (var i in unSet){
            Console.WriteLine(i);
        };
        if (unSet.Count >1){
            Console.WriteLine("Holaaaa");
        }else
        {Console.WriteLine("NOOOOOOOOOOOOOOO");}
        List<dynamic> unaLista = [];
        unaLista.Add("Inicio");
        unaLista.Add(1);
        unaLista.Add(2);
        unaLista.Add("Fin");
        foreach (var item in unaLista)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine(unaLista[2]);
        
        imprimirLista(unaLista);
        int a=0;
        masUnoParam(ref a);
        a=masUnoReturn(a);
        Console.WriteLine(a);
    }
    static void imprimirLista(List<dynamic> lista){
        foreach (var item in lista)
        {
            Console.WriteLine(item);   
        }
    }
    static void masUnoParam(ref int numero){
        numero++;
    }
    static int masUnoReturn(int numero){
        return ++numero;
    }
}

}