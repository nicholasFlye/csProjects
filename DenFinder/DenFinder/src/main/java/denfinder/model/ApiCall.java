package denfinder.model;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

/**
 * Created by landon on 10/6/14.
 */
public class ApiCall {
	
	private static String loadURL(String url) {
		
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
	
    public static JSONObject loadJSON(String url) throws IOException {
    	return new JSONObject(loadURL(url));
    }
    
    public static JSONArray loadJSONArray(String url) throws IOException {
    	return new JSONArray(loadURL(url));
    }
}

