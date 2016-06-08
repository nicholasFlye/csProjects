package denfinder.model;

import java.io.IOException;

import org.json.JSONException;

/**
 * Zone object
 * @author latch
 *
 */
public class Zone {
	
	// Lat long pair representing the center of the zone
	private Coordinates location;

	// How good of a match is this zone?
	private double rating = -1.0;
	
	// Contains the census data for this zone
	Fips fipsZone = null;
	
	
	/**
	 * Create new zone
	 * @param location the coordinates of the center point
	 * @throws IOException 
	 * @throws JSONException 
	 */
	public Zone(Coordinates location) throws JSONException, IOException {
		super();
		this.location = location;
	}

	/**
	 * Get location coordinates
	 * @return location
	 */
	public Coordinates getLocation() {
		return location;
	}


	/**
	 * Get how good a match this zone is to query
	 * @return match score, -1 if uninitialized
	 */
	public double getRating() {
		return rating;
	}
	
	public void setRating(double rating) {
		this.rating = rating;
	}

	public int getMedianIncome() {
		return fipsZone.getMedianIncome();
	}

	public void setMedianIncome(int medianIncome) {
		fipsZone.setMedianIncome(medianIncome);;
	}

	public double getMedianAge() {
		return fipsZone.getMedianAge();
	}

	public void setMedianAge(double medianAge) {
		fipsZone.setMedianAge(medianAge);
	}

	public int getNumSingle() {
		return fipsZone.getNumSingle();
	}

	public void setNumSingle(int numSingle) {
		fipsZone.setNumSingle(numSingle);
	}

	public int getNumMarried() {
		return fipsZone.getNumMarried();
	}

	public void setNumMarried(int numMarried) {
		fipsZone.setNumMarried(numMarried);
	}
	
	public Fips getFips() {
		return fipsZone;
	}
	
	public void setFips(Fips fipsZone) {
		this.fipsZone = fipsZone;
	}
}
