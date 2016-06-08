/**
 * 
 */
package denfinder.model;

import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import org.json.JSONArray;
import org.json.JSONException;

/**
 * @author PINTOR
 *
 */
public class SchoolSet implements Set<School> {

	private Set<School> schoolList;
	
	public SchoolSet() {
		this.schoolList = new HashSet<School>();
	}
	
	@Override
	public boolean add(School e) {
		return schoolList.add(e);
	}
	
	
	@Override
	public boolean addAll(Collection<? extends School> c) {
		return schoolList.addAll(c);
	}
	
	@Override
	public boolean contains(Object o) {
		return schoolList.contains(o);
	}
	
	@Override
	public boolean containsAll(Collection<?> c) {
		return schoolList.containsAll(c);
	}
	
	@Override
	public void clear() {
		schoolList.clear();
		
	}
	
	
	@Override
	public boolean isEmpty() {
		return schoolList.isEmpty();
	}
	
	@Override
	public Iterator<School> iterator() {
		return schoolList.iterator();
	}
	
	@Override
	public boolean removeAll(Collection<?> c) {
		return schoolList.removeAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		return schoolList.retainAll(c);
	}
	
	
	
	@Override
	public int size() {
		return schoolList.size();
	}

	@Override
	public Object[] toArray() {
		return schoolList.toArray();
	}

	@Override
	public <T> T[] toArray(T[] a) {
		return schoolList.toArray(a);
	}
	
		
	
	/**
	 * Populate list with all schools in a city, state, zip (must specify at least zipcode or state) 
	 * @param states a set of states to search
	 * @throws IOException if IO error
	 * @throws JSONException  if unreadable JSON format is returned
	 */
	public void populate(Set<String> states) throws JSONException, IOException{
		if(states == null || states.size() == 0){
			throw new IOException("Must specify at least one state for Education.com API to search");
		}
		
		for(String aState:states){
			//check for empty string state
			if(aState.length() <= 0)
				continue;
			
			//build query string for a state in the set of requested states
			EducationAPI anEducationAPICall = new EducationAPI("http://api.education.com/service/service.php?f=schoolSearch&key=" + Common.EDUCATION_KEY + "&sn=sf&v=4&state=" + aState + "&resf=json");
		        
			//submit query and read results
			JSONArray allSchoolsInState = anEducationAPICall.getResults();
		       
			//process each school in results
			for(int i = 0; i < allSchoolsInState.length(); i++){
				//data to read about each school
				String schoolName,id;
				double testRating,lat,lon;
            
				//read in data
				schoolName = allSchoolsInState.getJSONObject(i).getJSONObject("school").getString("schoolname");
				id = allSchoolsInState.getJSONObject(i).getJSONObject("school").getString("schoolid");
				String temp = allSchoolsInState.getJSONObject(i).getJSONObject("school").getString("testrating_text");
				if(temp.length() == 0){
					testRating = 0;
				}
				else{
					testRating = Double.parseDouble((allSchoolsInState.getJSONObject(i).getJSONObject("school").getString("testrating_text").substring(24)));
				}
				lat = allSchoolsInState.getJSONObject(i).getJSONObject("school").getDouble("latitude");
				lon = allSchoolsInState.getJSONObject(i).getJSONObject("school").getDouble("longitude");
            
				//create new school object and add to list
				School s = new School(id,testRating,new Coordinates(lat,lon));
				s.setName(schoolName);
				this.add(s);
            
				//print debugging information
				//System.out.println("[DEBUG] Adding school to school list: " + schoolName);
            
			}
		}
	}

	@Override
	public boolean remove(Object o) {
		// TODO Auto-generated method stub
		return false;
	}

}
