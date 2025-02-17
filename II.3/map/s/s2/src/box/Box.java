package box;

import java.util.ArrayList;
import java.util.List;

public class Box {

    private List<Tool> sachen = new ArrayList<>();

    public void add(Tool tool) {
        sachen.add(tool);
    }

    public List<Tool> heavyObject() {
        return sachen.stream().filter(sache -> sache.getWeight() > 1).toList();
    }

    public List<Tool> canCut() {
        return sachen.stream().filter(Tool::canCut).toList();
    }

    @Override
    public String toString() {
        return "Kiste{" +
                "sachen=" + sachen +
                '}';
    }
}
