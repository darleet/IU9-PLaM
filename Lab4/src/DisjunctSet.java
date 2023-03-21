import java.util.HashSet;
import java.util.Iterator;

public class DisjunctSet implements Iterable<Disjunct> {
    public HashSet<Disjunct> disjuncts = new HashSet<Disjunct>();
    private int size;

    public DisjunctSet() {
        this.size = 0;
    }

    public void addDisjunct(Disjunct entity) {
        disjuncts.add(entity);
        this.size++;
    }

    @Override
    public Iterator<Disjunct> iterator() {
        return new setIterator();
    }

    private class setIterator implements Iterator<Disjunct> {

        private int currentIndex = 0;
        private final Iterator<Disjunct> internalIterator = disjuncts.iterator();

        @Override
        public boolean hasNext() {
            return this.currentIndex < size;
        }

        @Override
        public Disjunct next() {
            Disjunct nextDisjunct = internalIterator.next();
            currentIndex++;
            if (nextDisjunct.isTrue()) {
                System.out.println(nextDisjunct);
            }
            return nextDisjunct;
        }
    }
}
