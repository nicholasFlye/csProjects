package denfinder.model;

import java.io.IOException;

import org.json.JSONException;

public class Fips {
	private String fipsCode;
	
	// Census data for this fips zone
    private int medianIncome = 0;
    private double medianAge = 0.0;
    private int numSingle    = 0;
    private int numMarried   = 0;
	
    
    // Make a blank fips with no census data:
	public Fips(String fips) throws IOException, JSONException {
		fipsCode = fips;
		
		CensusAPI census = new CensusAPI(fipsCode);
		
		setMedianIncome(census.getMedianIncome());
		setMedianAge(census.getMedianAge());
		setNumSingle(census.getNumSingle());
		setNumMarried(census.getNumMarried());
	}
	
	public String getFipsCode() {
		return fipsCode;
	}
	
	public void setFipsCode(String fipsCode) {
		this.fipsCode = fipsCode;
	}
	
	
	public int getMedianIncome() {
		return medianIncome;
	}

	public void setMedianIncome(int medianIncome) {
		this.medianIncome = medianIncome;
	}

	public double getMedianAge() {
		return medianAge;
	}

	public void setMedianAge(double medianAge) {
		this.medianAge = medianAge;
	}

	public int getNumSingle() {
		return numSingle;
	}

	public void setNumSingle(int numSingle) {
		this.numSingle = numSingle;
	}

	public int getNumMarried() {
		return numMarried;
	}

	public void setNumMarried(int numMarried) {
		this.numMarried = numMarried;
	}
	
	public boolean equals(Fips other) {
		return fipsCode.equals(other.getFipsCode());
	}
	
}
