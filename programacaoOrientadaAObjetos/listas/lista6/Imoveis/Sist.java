package listas.lista6.Imoveis;

import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Sist {
    public static int menu() {
        Scanner scan = new Scanner(System.in);
        System.out.println("--- ADMINISTRADORA DE IMOVEIS ---");
        System.out.println("1. Inserir imóvel");
        System.out.println("2. Encontrar imóvel");
        System.out.println("3. Calcular soma dos imóveis para venda");
        System.out.println("4. Calcular valor médio dos imóveis para alugar");
        System.out.println("5. Sair");
        System.out.print("Escolha a opção desejada: ");
        int op = scan.nextInt();
        return op;
    }

    public static void inserirImovel(List<Imovel> imoveis) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Identificação: ");
        int id = scan.nextInt();
        scan.nextLine();
        System.out.print("Nome do proprietario: ");
        String nomeProprietario = scan.nextLine();
        System.out.print("Endereco: ");
        String endereco = scan.nextLine();
        System.out.print("Venda ou aluguel?: ");
        String tipo = scan.nextLine();
        System.out.print("Valor: R$");
        double valor = scan.nextDouble();
        scan.nextLine();
        System.out.print("Categoria (Casa/Apartamento): ");
        String categoria = scan.nextLine();

        if(categoria.equals("Casa")) {
            System.out.print("Tem piscina? (Sim/Não): ");
            String temPiscina = scan.nextLine();

            Casa c1 = new Casa();
            c1.setId(id);
            c1.setNomeProprietario(nomeProprietario);
            c1.setEndereco(endereco);
            c1.setTipo(tipo);
            c1.setValor(valor);
            if(temPiscina.equals("Sim")) {
                c1.setComPiscina(true);
            } else if(temPiscina.equals("Não")) {
                c1.setComPiscina(false);
            }

            imoveis.add(c1);
        } else if(categoria.equals("Apartamento")) {
            System.out.print("Andar: ");
            int andar = scan.nextInt();
            System.out.print("Numero: ");
            int numero = scan.nextInt();

            Apto a1 = new Apto();
            a1.setId(id);
            a1.setNomeProprietario(nomeProprietario);
            a1.setEndereco(endereco);
            a1.setTipo(tipo);
            a1.setValor(valor);
            a1.setAndar(andar);
            a1.setNumero(numero);

            imoveis.add(a1);
        } else {
            System.out.println("Categoria invalida");
        }
    }

    public static void listarImovel(List imoveis, int id) {
        boolean achou = false;
        for(int i = 0; i < imoveis.size(); i++) {
            if(imoveis.get(i) instanceof Imovel) {
                Imovel im = (Imovel) imoveis.get(i);
                if(im.getId() == id) {
                    achou = true;
                    System.out.println("Imovel encontrado!");
                    System.out.println("Nome do proprietario: " + im.getNomeProprietario());
                    System.out.println("Endereco: " + im.getEndereco());
                    System.out.println("Tipo: " + im.getTipo());
                    System.out.println("Valor: R$" + im.getValor());

                    if(im instanceof Casa) {
                        Casa c1 = (Casa) im;
                        if(c1.isComPiscina()) {
                            System.out.println("Tem piscina: Sim");
                        } else System.out.println("Tem piscina: Não");
                    } else if(im instanceof Apto) {
                        Apto a1 = (Apto) im;
                        System.out.println("Andar: " + a1.getAndar());
                        System.out.println("Numero: " + a1.getNumero());
                    }
                }
            }
        }
        if(!achou) {
            System.out.println("Imovel nao encontrado");
        }
    }

    public static double somaImoveisVenda(List imoveis) {
        double soma = 0;
        for(int i = 0; i < imoveis.size(); i++) {
            if(imoveis.get(i) instanceof Imovel) {
                Imovel im = (Imovel) imoveis.get(i);
                if(im.getTipo().equals("Venda")) {
                    soma += im.getValor();
                }
            }
        }
        return soma;
    }

    public static double mediaImoveisAluguel(List imoveis) {
        double soma = 0;
        int count = 0;
        for(int i = 0; i < imoveis.size(); i++) {
            if(imoveis.get(i) instanceof Imovel) {
                Imovel im = (Imovel) imoveis.get(i);
                if(im.getTipo().equals("Aluguel")) {
                    soma += im.getValor();
                    count++;
                }
            }
        }

        return soma/count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<Imovel> imoveis = new ArrayList<>();
        int op;

        do {
            op = menu();
            switch (op) {
                case 1:
                    inserirImovel(imoveis);
                    break;
                case 2:
                    System.out.print("Insira o ID do imóvel: ");
                    int id = scan.nextInt();
                    listarImovel(imoveis, id);
                    break;
                case 3:
                    double soma = somaImoveisVenda(imoveis);
                    System.out.println(soma);
                    break;
                case 4:
                    double media = mediaImoveisAluguel(imoveis);
                    System.out.println(media);
                    break;
                default:
                    break;
            }
        } while (op != 5);
    }
}
