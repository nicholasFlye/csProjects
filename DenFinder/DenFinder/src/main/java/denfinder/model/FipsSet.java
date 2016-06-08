package denfinder.model;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class FipsSet implements Set<Fips> {

	private Set<Fips> fipsList;
	
	public FipsSet() {
		this.fipsList = new HashSet<Fips>();
	}
	
	
	@Override
	public int size() {
		return fipsList.size();
	}

	@Override
	public boolean isEmpty() {
		return fipsList.isEmpty();
	}

	@Override
	public Iterator<Fips> iterator() {
		return fipsList.iterator();
	}

	@Override
	public Object[] toArray() {
		return fipsList.toArray();
	}

	@Override
	public <T> T[] toArray(T[] a) {
		return fipsList.toArray(a);
	}

	public boolean contains(String fipsCode) {
		for (Fips aFips : fipsList) {
			if (aFips.getFipsCode().equals(fipsCode)) {
				return true;
			}
		}
		
		return false;
	}
	
	
	@Override
	public boolean contains(Object o) {
		return fipsList.contains(o);
	}
	
	public Fips getFips(String fipsCode) {
		for (Fips aFips : fipsList) {
			if (aFips.getFipsCode().equals(fipsCode)) {
				return aFips;
			}
		}
		return null;
	}
	
	
	@Override
	public boolean containsAll(Collection<?> c) {
		return fipsList.containsAll(c);
	}

	@Override
	public boolean add(Fips e) {
		return fipsList.add(e);
	}

	@Override
	public boolean remove(Object o) {
		return fipsList.remove(o);
	}
	
	@Override
	public boolean addAll(Collection<? extends Fips> c) {
		return fipsList.addAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		return fipsList.retainAll(c);
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		return fipsList.removeAll(c);
	}

	@Override
	public void clear() {
		fipsList.clear();
	}

}
