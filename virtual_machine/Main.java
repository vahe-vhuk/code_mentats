import compiler.Compiler;
import hardware.CPU;
import hardware.Loader;
import hardware.RAM;

public class Main {
    private static void compile_and_run(String file_name) throws Exception {
        Compiler compiler = new Compiler(file_name);
        compiler.do_compile();

        RAM ram = new RAM();

        Loader loader = new Loader(ram);
        loader.load(compiler.get_compiled_data());

        CPU cpu = new CPU();
        cpu.connect_to_ram(ram);
        cpu.run();

        ram.dump_memory();
    }

    public static void main(String[] args) throws Exception {
        compile_and_run(args[0]);
    }
}