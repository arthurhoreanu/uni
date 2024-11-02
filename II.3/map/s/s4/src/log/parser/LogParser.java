package log.parser;

import java.io.IOException;
import java.util.List;

import log.model.Log;

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
    List<Log> parseLogs(String path) throws IOException;
}
