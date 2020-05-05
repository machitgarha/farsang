<?php

// Ignore the first argument
$argc--;

if ($argc == 0) {
    echo "You must pass at least three arguments.", PHP_EOL;
    return 1;
}
if ($argc % 3 != 0) {
    echo "Argument count must be in a group of tripples.", PHP_EOL;
    return 1;
}

$string = <<<EXCEPTION
        class $1: public $2
        {
            public:
                $1() = delete;
                $1(const $1 &) = default;
                $1($1 &&) = default;

                using $2::$2;

                virtual inline Code getDefaultCode() const noexcept { return $3; }
        };
EXCEPTION;

for ($i = 0; $i < $argc / 3; $i++) {
    // Manipulation
    $result = $string;
    for ($j = 1; $j <= 3; $j++) {
        $result = str_replace("\$$j", $argv[3 * $i + $j], $result);
    }

    echo $result, PHP_EOL, PHP_EOL;
}

return 0;
