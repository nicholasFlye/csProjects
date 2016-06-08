package denfinder.controllers;

import denfinder.model.*;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import java.io.IOException;

@Controller
public class MainController {
	@RequestMapping("/")
	public String home(Model model) {
        model.addAttribute("formData", new FormData());
		return "index";
	}
	
	@RequestMapping("/map")
	public String map() {
		return "map";
	}

    @RequestMapping(value="/results", method=RequestMethod.GET)
    public String results(@ModelAttribute FormData formData, Model model) throws IOException {

    	Map map = new Map(formData.getAddress(), formData.getIncome(), formData.getRelationship(), formData.getAge(), formData.getSchool());
    	
        model.addAttribute("formData", formData);
        model.addAttribute("map", map);
        
        return "results";
    }
}