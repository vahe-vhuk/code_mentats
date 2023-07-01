package hardware;

import hardware.exceptions.SegmentationFaultError;
import hardware.exceptions.ZeroDivisionError;


public class CPU {
    private RAM ram;

    private byte ayb = 0;
    private byte ben = 0;
    private byte gim = 0;
    private byte da = 0;
    private byte ech = 0;
    private byte za = 0;
    private byte gh = 0;

    public CPU() {

    }

    public void connect_to_ram(RAM ram) {
        this.ram = ram;
    }

    public void run() throws Exception {
        this.gh = 0;
        while (this.gh < get_code_size()) {
            byte[] cell = this.ram.get(this.gh);

            execute(cell);

            this.gh += 1;
        }
        System.out.println(get_code_size());
    }

    private void execute(byte[] cell) throws SegmentationFaultError, ZeroDivisionError {
        byte val1;
        byte val2;
        switch (cell[0]) {
            case 0 -> {
                this.ayb = read_data(cell[2]);
                save_data(cell[1]);
            }
            case 1 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = add(val1, val2);
                save_data(cell[1]);
            }
            case 2 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = sub(val1, val2);
                save_data(cell[1]);
            }
            case 3 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = mul(val1, val2);
                save_data(cell[1]);
            }
            case 4 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = div(val1, val2);
                save_data(cell[1]);
            }
            case 5 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = and(val1, val2);
                save_data(cell[1]);
            }
            case 6 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                this.ayb = or(val1, val2);
                save_data(cell[1]);
            }
            case 7 -> {
                val1 = read_data(cell[1]);
                this.ayb = not(val1);
                save_data(cell[1]);
            }
            case 8 -> {
                val1 = read_data(cell[1]);
                val2 = read_data(cell[2]);
                cmp(val1, val2);
            }
            case 9 -> {
                val1 = read_data(cell[1]);
                jmp(val1);
            }
            case 10 -> {
                val1 = read_data(cell[1]);
                jg(val1);
            }
            case 11 -> {
                val1 = read_data(cell[1]);
                jl(val1);
            }
            case 12 -> {
                val1 = read_data(cell[1]);
                je(val1);
            }
        }
    }

    private byte read_data(byte address) throws SegmentationFaultError {
        int code_size = get_code_size() + 1;
        if (address < 0) {
            return (byte)(-address - 1);
        }
        if (address < code_size + 1 || address > 36) {
            throw new SegmentationFaultError();
        }

        if (address <= 31) {
            return this.ram.get(address)[0];
        }
        return switch (address) {
            case 32 -> this.ayb;
            case 33 -> this.ben;
            case 34 -> this.gim;
            case 35 -> this.da;
            case 36 -> this.ech;
            default -> 0;
        };
    }

    private void save_data(byte address) throws SegmentationFaultError {
        if (address < get_code_size() + 1 || address > 36) {
            throw new SegmentationFaultError();
        }
        if (address <= 31) {
            this.ram.set(address, this.ayb);
        }
        switch (address) {
            case 32 : break;
            case 33 : this.ben = this.ayb;break;
            case 34 : this.gim = this.ayb;break;
            case 35 : this.da = this.ayb;break;
            case 36 : this.ech = this.ayb;break;
        };
    }

    private byte add(byte a, byte b) {
        int res = a + b;
        if (res < -128 || res > 127) {
            this.za |= 1;
        }
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte sub(byte a, byte b) {
        int res = a - b;
        if (res < -128 || res > 127) {
            this.za |= 1;
        }
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte mul(byte a, byte b) {
        int res = a * b;
        if (res < -128 || res > 127) {
            this.za |= 1;
        }
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte div(byte a, byte b) throws ZeroDivisionError {
        if (b < 0) {
            throw new ZeroDivisionError();
        }
        int res = a / b;
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte and(byte a, byte b) {
        int res = a & b;
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte or(byte a, byte b) {
        int res = a | b;
        if (res < -128 || res > 127) {
            this.za |= 1;
        }
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private byte not(byte a) {
        int res = ~a;
        if (res < -128 || res > 127) {
            this.za |= 1;
        }
        if (res < 0) {
            this.za |= 2;
        }
        return (byte)(res);
    }

    private void cmp(byte a, byte b) {
        byte res = sub(a, b);
        if (res == 0) {
            this.za |= 4;
        }
    }

    private void jmp(byte a) {
        System.out.println(46595);
        this.gh = (byte)(a - 1);
    }

    private void jg(byte a) {
        if ((this.za & 5) == 0) {
            this.gh = (byte)(a - 1);
        }
    }

    private void jl(byte a) {
        if ((this.za & 2) == 2) {
            this.gh = (byte)(a - 1);
        }
    }

    private void je(byte a) {
        if ((this.za & 4) == 4) {
            this.gh = (byte)(a - 1);
        }
    }


    private int get_code_size() {
        int size = 0;
        while (true) {
            byte[] cell = ram.get(size);
            if (cell[0] == 0 && cell[1] == 0 && cell[2] == 0) {
                break;
            }
            size += 1;
        }

        return size;
    }
}
