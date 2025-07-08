package provas.P2.prova24_1.questao1;

import java.util.Scanner;
import java.util.Iterator;
import java.util.List;

public class Principal {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        LivroDeBiblioteca b1 = new LivroDeBiblioteca("Garden of Abdul Gasazi", "Chris Allsburg", 2006, "1");
        LivroDeBiblioteca b2 = new LivroDeBiblioteca("Collected Poems of Lucille Clifton", "Michael Glaser", 2005, "2");
        LivroDeLivraria l1 = new LivroDeLivraria("Going Places", "Peter Reynolds", 2004, "3");
        LivroDeLivraria l2 = new LivroDeLivraria("Anathem", "Neal Stephenson", 2003, "4");

        Instituicao i = new Instituicao();
        i.inserir(b1);
        i.inserir(b2);
        i.inserir(l1);
        i.inserir(l2);

        List<Livro> listaLivros = i.retornarLista();
        imprimeRelatorioGeral(listaLivros);

        System.out.print("Qual o ISBN do livro a ser consultado?: ");
        Livro l = new Livro(scan.nextLine());
        if(listaLivros.contains(l)) {
            l = listaLivros.get(listaLivros.indexOf(l));
            System.out.println("Título: " + l.getTitulo());
            System.out.println("Autor: " + l.getAutor());
            System.out.println("Ano: " + l.getAno());
        } else System.out.println("ERRO: Livro não encontrado");

        scan.close();
    }

    public static void imprimeRelatorioGeral(List<Livro> list) {
        Iterator<Livro> it = list.iterator();

        while(it.hasNext()) {
            Livro atual = it.next();
            System.out.println("Título: " + atual.getTitulo());
            System.out.println("Autor: " + atual.getAutor());
            System.out.println("Ano: " + atual.getAno());
            System.out.println("ISBN: " + atual.getIsbn());
            
            if(atual instanceof LivroDeBiblioteca) {
                LivroDeBiblioteca b = (LivroDeBiblioteca) atual;
                System.out.print("Alugado: ");
                if(b.isAlugado()) System.out.println("Sim");
                else System.out.println("Não");
            } else if(atual instanceof LivroDeLivraria) {
                LivroDeLivraria l = (LivroDeLivraria) atual;
                System.out.print("Vendido: ");
                if(l.isVendido()) System.out.println("Sim");
                else System.out.println("Não");
            }
        }
    }
}
