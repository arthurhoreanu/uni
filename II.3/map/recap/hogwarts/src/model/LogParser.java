package model;

import java.io.IOException;
import java.util.List;

@FunctionalInterface
public interface LogParser {

    /**
     * This method reads the logs from the logfile
     *
     * @param path
     *         the path of the logfile
     * @return the list of {@link Log}s
     * @throws IOException
     *         in case of I/O exceptions
     */
    List<Log> parse(String path) throws IOException;
}
