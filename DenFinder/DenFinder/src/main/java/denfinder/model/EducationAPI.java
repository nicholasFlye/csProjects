/**
 *  by Nicholas Flye
 */

package denfinder.model;

import org.json.JSONArray;
import org.json.JSONException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

/**
 * Contains education data
 *
 */
public class EducationAPI {
	String itsQuery;
	JSONArray queryResults;
	
	/**
	 * Create new education data
	 * @param coords the coordinates to query
	 */
	public EducationAPI(String queryUrl) throws IOException {
        this.itsQuery = queryUrl;
	}
	
	/**
	 * Run query (if needed) and return results
	 * @return query string results
	 * @throws JSONException if unrecognized JSON format
	 * @throws IOException if IO error
	 */
	public JSONArray getResults() throws JSONException, IOException{
		if (this.queryResults == null)
			performQuery();
		return this.queryResults;
	}
	
	/**
	 * Get current query string
	 * @return current query url
	 */
	public String getQueryString(){
		return this.itsQuery;
	}
	
	/**
	 * Set query string
	 * @param newQuery new url encoded education query
	 */
	public void setQuery(String newQuery){
		this.itsQuery = newQuery;
	}

	/**
	 * Perform query specified in query string
	 * @throws JSONException
	 * @throws IOException
	 */
	private void performQuery() throws JSONException, IOException{
		//submit query and read results
		this.queryResults = new JSONArray(educationContent(this.itsQuery));
	}
	
	/**
	 * Reads all education content from url
	 * @param url query to read from
	 * @return read content
	 * @throws IOException if IO error
	 */
	private static String educationContent(String url) throws IOException {

        StringBuilder content = new StringBuilder();
        try
        {

            URL censusURL = new URL(url);
            URLConnection urlConnection = censusURL.openConnection();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
            String line;

            while ((line = bufferedReader.readLine()) != null){

                content.append(line + "\n");
            }
            bufferedReader.close();

        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return content.toString();
    }
	
}
