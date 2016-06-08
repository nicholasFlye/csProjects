/**
 * 
 */
package denfinder.model;

/**
 * @author PINTOR
 *
 */
public class School {
	
	private double testRating;
	private Coordinates location;
	private String ID;
	private String name;
	
	public School() {
		//set up default values for a school
		testRating = 0.0;
		this.location.latitude = this.location.longitude = 0.0;
		ID = "00000";
	}
	
	public School(String aID, double aTestRating,
				  Coordinates aLocation) {
		
		ID = aID;
		testRating = aTestRating;
		this.location = aLocation;
	}

	public String getID() {
		return ID;
	}

	public void setID(String iD) {
		ID = iD;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}

	public double getTestRating() {
		return testRating;
	}

	public void setTestRating(double testRating) {
		this.testRating = testRating;
	}

	

	public Coordinates getLocation() {
		return location;
	}

	public void setLocation(Coordinates newLocation) {
		this.location = newLocation;
	}
	
}
