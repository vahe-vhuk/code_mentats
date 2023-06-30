package compiler;

import java.util.ArrayList;

public class PreProcessor {
    private final ArrayList<String> code;

    public PreProcessor(ArrayList<String> code) {
        this.code = code;
    }

    public void do_preprocess() {
        for (int i = 0; i < this.code.size(); ++i) {
            String line = this.code.get(i);
            if (line.contains("#")) {
                this.code.set(i,line.substring(0,line.indexOf("#")));
            }
        }
    }
}
