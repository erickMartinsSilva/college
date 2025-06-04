public class Planta implements Comparable<Planta> {
    private String id;
    private String nome;
    private double tamanho;

    public Planta(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getTamanho() {
        return tamanho;
    }

    public void setTamanho(double tamanho) {
        this.tamanho = tamanho;
    }

    public int compareTo(Planta p) {
        return Double.compare(this.getTamanho(), p.getTamanho());
    }

    public boolean equals(Object o) {
        if(o instanceof Planta) {
            Planta p = (Planta) o;
            return this.getId().equals(p.getId());
        }
        return false;
    }

    public String toString() {
        return "ID: " + id + ", Nome: " + nome + ", Tamanho: " + tamanho + " cm";
    }
}