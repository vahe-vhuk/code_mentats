package hardware;

import hardware.exceptions.LoadError;

import java.util.ArrayList;

public class Loader {
    private RAM ram;
    public Loader(RAM ram) {
        this.ram = ram;
    }

    public void load(ArrayList<Byte> compiled_data) throws Exception {
        if (compiled_data.size() > this.ram.get_ram_size()) {
            throw new LoadError();
        }
        byte[] memory = ram.get_memory();

        for (int i = 0; i < compiled_data.size(); ++i) {
            memory[i] = compiled_data.get(i);
        }
    }
}
