package hardware;

public class RAM {
    private final int ram_size = 96;
    private byte[] memory;

    public RAM() {
        this.memory = new byte[this.ram_size];
    }

    public int get_ram_size() {
        return this.ram_size;
    }
    public byte[] get_memory() {
        return this.memory;
    }

    public byte[] get(int address) {
        byte[] res = new byte[3];
        address *= 3;
        res[0] = this.memory[address];
        res[1] = this.memory[address + 1];
        res[2] = this.memory[address + 2];
        return res;
    }

    public void set(int address, byte value) {
        this.memory[address * 3] = value;
    }

    public void dump_memory() {
        for (int i = 0; i < this.ram_size; i += 3) {
            if (this.memory[i + 1] != 0) {
                String res = this.memory[i] + " " + this.memory[i + 1] + " " + this.memory[i + 2];
                System.out.println((i / 3) + ": " + res);
            }
            else {
                System.out.println((i / 3) + ": " + this.memory[i]);
            }
        }
    }
}
